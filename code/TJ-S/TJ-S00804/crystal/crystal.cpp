#include<bits/stdc++.h>
using namespace std;
long long n,m,a,ans=-1,cnt=0,k=0;
vector<long long> v,vc;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
		vc.push_back(0);
	}
	sort(v.begin(),v.end());
	for(int i=1;i<v.size();i++){
//		cout<<v[i]<<" ";
		long long cha;
		cha=v[i]-v[i-1];
//		cout<<cha<<" ";
		if(cha==0){
			cnt=i-k+1;
//			cout<<cnt<<" "<<i<<" "<<k<<"\n";
			ans=max(ans,cnt);
			continue;
		}
		for(int j=k;j<i;j++){
//			cout<<j<<" ";
			cnt=(m-vc[j])/cha;
			if(cnt>=i-j){
				long long l=i-j+1;
				ans=max(ans,l);
//				cout<<vc[j]<<" "<<i<<" "<<j<<" "<<l<<"\n";
			}
			vc[j]=vc[j]+(i-j)*cha;
			if(vc[j]>m){
				k++;
//				cout<<j<<" "<<vc[j]<<"\n";
			}
//			cout<<j<<" "<<vc[j]<<"\n";
		}
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
