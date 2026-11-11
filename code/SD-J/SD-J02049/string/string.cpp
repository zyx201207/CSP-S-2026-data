#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
int fr,ba;
long long ans;
int cnta,cntb;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	fr=1,ba=n;
	cnta=a[fr],cntb=a[ba];
	while(fr<=ba){
		if(c[fr]!=c[ba]){
			if(cnta>cntb){
				ans+=cntb;
				cnta-=cntb;
				ba--;
				cntb=a[ba];
			}
			else if(cnta<cntb){
				ans+=cnta;
				cntb-=cnta;
				fr++;
				cnta=a[fr];
			}
			else{
				ans+=cnta;
				fr++,ba--;
				cnta=a[fr];
				cntb=a[ba];
			}
		}
		else{
			if(cnta>cntb){
				cnta-=cntb;
				ba--;
				cntb=a[ba];
			}
			else if(cnta<cntb){
				cntb-=cnta;
				fr++;
				cnta=a[fr];
			}
			else{
				fr++,ba--;
				cnta=a[fr];
				cntb=a[ba];
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
