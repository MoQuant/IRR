#include <iostream>
#include <math.h>
#include <vector>
#include <string>

double dNPV(std::vector<double> cf, double cost_of_capital)
{
  double dnpv = 0;
  for(int i = 0; i < cf.size(); ++i){
    dnpv = -(i*cf[i])/pow(1 + cost_of_capital, i+1);
  }
  return dnpv;
}

double NPV(std::vector<double> cf, double cost_of_capital)
{
  double npv = 0;
  for(int i = 0; i < cf.size(); ++i){
    npv = npv + cf[i]/pow(1+cost_of_capital, i);
  }
  return npv;
}

int main()
{
  std::cout << "IRR Function" << std::endl;

  std::vector<double> cost = {-100, 20, 30, 40, 50, 60};

  double irr_0 = 0.11, irr_1 = 0.89;
  double error = 0.000001;

  while(true){
    irr_1 = irr_0 - NPV(cost, irr_0)/dNPV(cost, irr_0);
    if(abs(irr_1 - irr_0) < error){
      break;
    }
    irr_0 = irr_1;
  }

  double check_total = 0;
  for(int i = 0; i < cost.size(); ++i){
    check_total += cost[i]/pow(1 + irr_1, i);
  }

  std::cout << "If not = to zero, this is wrong: " << check_total << std::endl;

  return 0;
}
