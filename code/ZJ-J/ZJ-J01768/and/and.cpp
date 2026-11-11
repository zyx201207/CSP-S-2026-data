#include<bits/stdc++.h>
using namespace std;
int n,m,mw;
struct nod{
	bool ky;
	long long z;
	int ws;
	bool w[35];
}s[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i].z ;
		long long ls=s[i].z ,cnt=0;
		while(ls){
			s[i].w [cnt]=ls%2;
			ls/=2;
			cnt++;
		}
		s[i].ws =cnt-1;
		mw=max(mw,s[i].ws );
//		for(int j=mw ;j>=0;j--){
//			cout<<s[i].w [j];
//		}
//		cout<<"\n";
	}
	long long cnt=0;
	long long dx=1;
	for(int i=0;i<mw;i++){
		dx*=2;
	}
//	cout<<dx<<"\n";
//	cout<<"\n";
	int pd=0;
	for(int i=mw;i>=0;i--){
//		cout<<mw<<"\n";
		int p=0;
		for(int j=0;j<n;j++){
			if(s[j].w [i]==1){
//				cout<<s[j].z <<" ";
				p++;
			}
		}
//		cout<<"\n";
		if(p>=m){
//			cout<<111<<" "<<p<<" "<<m<<"\n";
			pd=1;
			for(int j=0;j<n;j++){
				if(s[j].w [i]==1){
					s[j].ky =1;
				}
			}
			break;
		}
		dx/=2;
		mw--;
	}
//	cout<<"\n";
	if(pd==0){
		cout<<0;
		return 0;
	}
	mw--;
	cnt+=dx;
	dx/=2;
//	cout<<cnt<<"\n";
//	for(int j=0;j<n;j++){
//		cout<<s[j].ky <<" ";
//	}
//	cout<<"\n\n";
	for(int i=mw;i>=0;i--){
		int p=0;
		for(int j=0;j<n;j++){
			if(s[j].ky ==1&&s[j].w [i]==1){
				p++;
			}
		}
//		cout<<cnt<<" "<<p<<" "<<m<<"\n";
//		for(int j=0;j<n;j++){
//			cout<<s[j].ky <<" ";
//		}
//		cout<<"\n";
		if(p>=m){
			cnt+=dx;
			for(int j=0;j<n;j++){
				if(s[j].w [i]==0){
					s[j].ky =0;
				}
			}
		}
		dx/=2;
		mw--;
	}
	cout<<cnt;
	return 0;
}
/*
5 3
31 3 1 15 7
*/