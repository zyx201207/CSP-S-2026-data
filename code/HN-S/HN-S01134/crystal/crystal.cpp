#include<bits/stdc++.h>
using namespace std;
const int N=501000;
int n,m,maxx=-1;
int power[N],tie[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>power[i];
	sort(power,power+n);
	tie[0]=1;
	for(int i=0;i<n;i++){
		if(power[i+1]==power[i]) tie[0]++;
		else break;
	}
	for(int i=1;i<n;i++){
		if(power[i]==power[i-1]){
			tie[i]=tie[i-1];
			break;
		}
		int a=1,b=m;
		for(int p=i+1;p<n;p++){
			if(power[p]==power[i]) a++;
			else break;
		}
		tie[i]+=a;
		for(int j=i-1;j>=0;j--){
			int x=power[i]-power[j];
			if(b>=x){
				tie[i]++;
				b-=x;
			}
			else break;
		}
	}
	for(int i=0;i<n;i++) if(tie[i]>maxx) maxx=tie[i];
	cout<<maxx;
	return 0;
}
/*
Oct31==Dec25?
*/
