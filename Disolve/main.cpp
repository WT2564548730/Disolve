#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    Solution(int num) {
        n = num;
    }
    void solve();//将n分解为素因子的乘积
private:
    int n;
};

bool isPrime(int n){
    int flag=0;
    if(n==1||n==2||n==3)
        return true;
    else{
        for(int i=2;i<=sqrt(n);i++){
            if(n%i!=0)
                flag=1;
            else{
                flag=0;
                break;
            }
        }
        if(flag==1)
            return true;
        else
            return false;
    }
}

void Solution::solve(){
    int f=0;
    if(isPrime(n))
        cout<<n<<"="<<n<<endl;
    else{
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0&&isPrime(i)){
                f++;
                if(f==1)
                    cout<<n<<"="<<i;
                else
                    cout<<"*"<<i;
                n/=i;
                i--;
            }
        }
        cout<<"*"<<n<<endl;
    }
}

int main()
{
    int n;
    while (cin >> n) {
        Solution obj(n);
        obj.solve();
    }
    return 0;
}
