#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	ll cbdamt=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i=1;i<n;i++){
		int M=m;
		ll cz=0;
		for(int j=0;j<i;j++){
			cz+=arr[i]-arr[j];
		}
		M-=cz;
		cbdamt=i+1;
		if(M==0){
			for(int j=i+1;j<n;j++){
				if(arr[i]==arr[j]){
					cbdamt++;
				}else{
					cout<<cbdamt;
					return 0;
				}
			}
		}
		if(M<0){
			cbdamt--;
			cout<<cbdamt;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
