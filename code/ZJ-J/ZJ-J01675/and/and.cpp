#include<bits/stdc++.h>
using namespace std;
long long rjz[50];
long long s[200005];
int stp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;	
	cin>>n>>m;
	long long ma=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		ma=max(s[i],ma);
	}
	long long a=1;
	for(int i=1;i<=40;i++){
		rjz[i]=a;
		a*=2;
	}
	int b=1;
	while(ma>=rjz[b]){
		b++;
	}
	long long mm=0;
	while(b){
//		cout<<rjz[b]<<endl;
		int bj=0;
		for(int i=1;i<=n;i++){
			if((s[i]&rjz[b])!=0){
				bj++;															
//				cout<<"*"<<s[i]<<" "<<(s[i]&rjz[b])<<endl;
			}
		}
		
		if(bj>=m){
			for(int i=1;i<=n;i++){
				if((s[i]&rjz[b])==0){
					s[i]=0;
				}
//				cout<<s[i]<<" "<<rjz[b]<<"   ";
			}
//			cout<<endl;
			mm+=rjz[b];	
		}
//		if(bj==m){
//			break;
//		}
		b--;
	}
	cout<<mm;
	return 0;
}