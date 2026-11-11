#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long m;
const int N=5e5+10;
long long marui[N];
long long he[N];
long long he1[N];
long long tong[N];
long long tong1[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>marui[i];
	}
	sort(marui+1,marui+1+n);
	for(int i=1;i<n;i++){
		he[i]=marui[i+1]-marui[i];
		he1[i]=he1[i-1]+he[i];
		tong[i]=he1[i];
		tong1[i]=1;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(he1[i]-he1[j]>=0){
				tong[i]+=he1[i]-he1[j];
				tong1[i]++;
			}
			else{
				break;
			}
		}
	}
	for(int i=n;i>=1;i--){
		if(tong[i]==m){
			cout<<tong1[i];
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
