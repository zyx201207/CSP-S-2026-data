#include<bits/stdc++.h>
using namespace std;
long long n;
vector<char>sum;
vector<int>s(n);
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cout<<"2";
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>s[i];
        if(s[i] >= 0){
           sum[i] = "a";
        }
        else{
            sum[i] = "b";
        }
    }
    int total = 0;
    for(int i = 1;i<= n;i++){
        if(i <= 2 && sum[i] != "a"){
                total++;
        }
        if(i == 3 && sum[i] != "b"){
                total++;
        }
    }
fclose;
cout<<total;
return 0;
}
