#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,cnt,x[500000];
char a[5000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>a[i];
	}
	int j=n,i=1;
	for(int k=1;k<=n;k++){
		if(j==0||i>n)break;
		if(a[i]!=a[j]){
			if(x[i]<x[j]){
				cnt+=x[i];
				x[j]-=x[i];
				x[i]=0;
				i++;
			}else if(x[i]>x[j]){
				cnt+=x[j];
				x[i]-=x[j];
				x[j]=0;
				j--;
			}else{
				cnt+=x[j];
				x[i]-=x[j];
				x[j]=0;x[i]=0;
				j--;i++;
			}
		}else{
			if(x[i]<x[j]){
				x[j]-=x[i];
				x[i]=0;
				i++;
			}else if(x[i]>x[j]){
				x[i]-=x[j];
				x[j]=0;
				j--;
			}else{
				x[i]-=x[j];
				x[j]=0;x[i]=0;
				j--;i++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

