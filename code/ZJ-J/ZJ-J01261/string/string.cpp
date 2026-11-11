#include<bits/stdc++.h>
using namespace std;
int n,sum;
long long k1,k2;
struct yyds{
	char c;
	int a;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		k1+=s[i].a;
	}
	k1/=2;
	for (int i=1;i<=n;i++){
		k2+=s[i].a;
		if (k2<=k1&&k2+s[i+1].a>=k1){
			k1=k2+s[i+1].a-k1;
			k2=s[i+1].a-k1;
			continue;
		}
	}
	int r=1,l=n,x=s[r].a,y=s[l].a;
	char xx=s[r].c,yy=s[r].c;
	while(r!=l){
		if (abs(r-l)==2){
			if (xx==yy){
				if (x>y){
					x=x-y;
					--l;
					yy=k2;
				}
				else if(x<y){
					y=y-x;
					++r;
					xx=k1;
				}
				else{
					++r;
					--l;
					xx=k1;
					yy=k2;
				}
			}
			else{
				if (x>y){
					sum+=y;x=x-y;
					y=s[--l].a;
					yy=s[l].c;
				}
				else if(x<y){
					sum+=x;
					y=y-x;
					x=s[++r].a;
					xx=s[r].c;
				}
				else{
					sum+=y;
					x=s[++r].a;
					y=s[--l].a;
					xx=s[r].c;
					yy=s[l].c;
				}
			}
		}
		else{
			if (xx==yy){
				if (x>y){
					x=x-y;
					y=s[--l].a;
					yy=s[l].c;
				}
				else if(x<y){
					y=y-x;
					x=s[++r].a;
					xx=s[r].c;
				}
				else{
					x=s[++r].a;
					y=s[--l].a;
					xx=s[r].c;
					yy=s[l].c;
				}
			}
			else{
				if (x>y){
					sum+=y;x=x-y;
					y=s[--l].a;
					yy=s[l].c;
				}
				else if(x<y){
					sum+=x;
					y=y-x;
					x=s[++r].a;
					xx=s[r].c;
				}
				else{
					sum+=y;
					x=s[++r].a;
					y=s[--l].a;
					xx=s[r].c;
					yy=s[l].c;
				}
			}
		}
		
	}
	cout<<sum;
	return 0;
}