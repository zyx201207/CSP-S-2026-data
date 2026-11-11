#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct s{
	int cnt;
	char c;
	int sum;
}num[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%lld",&n);
	int m=n;
	int cn=0;
	int j=1;
	for(int i=1;i<=n;i++,j++){
		int p;
		char cm;
		cin>>p>>cm;		
		if(cm==num[j-1].c){
			num[--j].cnt+=p;
			m--;	
		}else{
			num[j].c=cm;
			num[j].cnt=p;
		}
		cn+=num[j].cnt;
		num[j].sum=num[j-1].sum+num[j].cnt;
	}
	/*for(int i=1;i<=m;i++){
		cout<<num[i].c<<num[i].cnt<<'\n';
	}*/
	int cn1;
	if(cn%2==1){
		cn1=cn/2+1;
	}else cn1=cn/2;
	
	int x;
	for(int i=1;i<=m;i++){
		if(num[i].sum>=cn1){
			x=i;
			break;
		}
	}
	//cout<<x; 
	int ans=0;
	if(cn%2==1){
		num[x].cnt--;
	}else if(cn1==num[x].sum){
		num[x+1].cnt--;
	}else num[x].cnt-=2;
	
	int l=1,r=m;
	int cnl=num[l].cnt;
	int cnr=num[r].cnt;
	while(l<r){			
		if(num[l].c==num[r].c){
			if(cnl<cnr){
				l++;
				cnr-=cnl;
				cnl=num[l].cnt;	
			}else if(cnl>cnr){
				r--;
				cnl-=cnr;
				cnr=num[r].cnt;
			}else{
				l++,r--;
				cnl=num[l].cnt,cnr=num[r].cnt;
			}	
		}else{
			if(cnl<cnr){
				l++;
				ans+=cnl;
				cnr-=cnl;
				cnl=num[l].cnt;
			}else if(cnl>cnr){
				r--;
				ans+=cnr;
				cnl-=cnr;
				cnr=num[r].cnt;
			}else{
				l++,r--;
				ans+=cnl;
				cnl=num[l].cnt,cnr=num[r].cnt;
			}
		}
	}
	
	cout<<ans;
	return 0;
}
