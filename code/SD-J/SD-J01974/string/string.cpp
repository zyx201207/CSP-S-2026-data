#include<bits/stdc++.h>
using namespace std;
#define int long long
struct bbcd{
	int cnt;
	char cc;
}s[200020];
int n;
signed main(){
	freopen("string5.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int id;
		char c;
		cin>>id>>c;
		s[i].cnt=id;
		s[i].cc=c;
	}
	int ans=0;
	int l=1,r=n;
	int cn=0;
	char now='1';
	while(l<=r){
		int cntr=s[r].cnt;
		int cntl=s[l].cnt;
		char cr=s[r].cc;
		char cl=s[l].cc;
		if(r==l){
			if(cn==0){
			}
			else if(cn>0){
				if(now!=cl){
					ans+=min(cn,cntl);
				}
			}
			else{
				if(now!=cr){
					ans+=min(cn*-1,cntr);
				}
			}
			r--;
			l++;
		}
		else if(cn*-1>cntr){
			if(now!=cr){
				ans+=cntr;
			}
			cn+=cntr;
			r--;
		}
		else if(cn>cntl){
			if(now!=cl){
				ans+=cntl;
			}
			cn-=cntl;
			l++;
		}
		else{
			if(cn>0){
				if(now!=cl){
					ans+=cn;
				}
				cntl-=cn;
			}
			else{
				if(now!=cr){
					ans+=cn*-1;
				}
				cntr+=cn;
			}
			int cnn=cntr-cntl;
			if(cnn>0){
				if(cr!=cl){
					ans+=cntl;
				}
				now=cl;
			}
			if(cnn<0){
				if(cr!=cl){
					ans+=cntr;
				}
				now=cr;
			}
			else{
				if(cr!=cl){
					ans+=cntr;
				}
				now='1';
			}
			cn=cnn;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
