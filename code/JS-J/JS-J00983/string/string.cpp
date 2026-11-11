#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x[200005],x_rest,sum=0;
    char y[200005],y_rest;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1,j=n;i<j;){
        if(y[i]==y[j]){
            if (x[i]>x[j]){
                x[i]-=x[j];
                j--;
            }
            else if(x[i]==x[j]){
                i++;
                j--;
            }
            else if(x[i]<x[j]){
                x[j]-=x[i];
                i++;
            }
        }
        else {
            if (x[i]>x[j]){
                sum+=x[j];
                x[i]-=x[j];
                j--;
            }
            else if(x[i]==x[j]){
                sum+=x[i];
                i++;
                j--;
            }
            else if(x[i]<x[j]){
                sum+=x[i];
                x[j]-=x[i];
                i++;
            }
        }
    }
    cout<<sum;
	return 0;
}