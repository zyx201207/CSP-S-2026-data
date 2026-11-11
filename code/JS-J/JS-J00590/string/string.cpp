#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n;
int num1[N],num2[N];
char a1[N],a2[N];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>num1[i]>>a1[i];
        num2[n-i+1] = num1[i];
        a2[n-i+1] = a1[i];
    }
    /*for(int i = 1;i <= n;i++){
        for(int j = 1;j <= num1[i];j++)cout<<a1[i];
    }
    cout<<endl;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= num2[i];j++)cout<<a2[i];
    }*/
    int i,j;

    for(i = 1,j = 1;i <= n && j <= n;){
        if(a1[i] == a2[j]){
            if(num1[i] > num2[j]){
                num1[i] -= num2[j];
                j++;
            }
            else if(num1[i] < num2[j]){
                num2[j] -= num1[i];
                i++;
            }
            else if(num1[i] == num2[j]){
                i++;
                j++;
            }
        }
        else{
            if(num1[i] == num2[j]){
                ans += num1[i];
                i++;
                j++;
            }
            else if(num1[i] > num2[j]){
                ans += num2[j];
                num1[i] -= num2[j];
                j++;
            }
            else if(num1[i] < num2[j]){
                ans += num1[i];
                num2[j] -= num1[i];
                i++;
            }
        }
    }
    cout<<ans/2<<endl;
    return 0;

}
