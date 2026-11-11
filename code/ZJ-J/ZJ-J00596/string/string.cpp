#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
struct node{
	int len;
	char c;
}a[N];
int n,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
	}
	int cnti=a[1].len;
	int cntj=a[n].len;
	for(int i=1,j=n;i<=j;){
		if(cnti>cntj){
			if(a[i].c==a[j].c){
				cnti-=cntj;
				cntj=0;
			}else{
				cnti-=cntj;
				ans+=cntj;
				cntj=0;
			}
		}else{
			if(a[i].c==a[j].c){
				cntj-=cnti;
				cnti=0;
			}else{
				cntj-=cnti;
				ans+=cnti;
				cnti=0;
			}
		}
		if(cnti==0){
			i++;
			cnti+=a[i].len;
		}
		if(cntj==0){
			j--;
			cntj+=a[j].len;
		}
	}
	cout<<ans;
}
