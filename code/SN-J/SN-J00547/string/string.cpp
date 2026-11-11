#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PID "string"
#define FIN freopen(PID".in","r",stdin)
#define FOU freopen(PID".out","w",stdout)
struct node{
	char c;
	int l;
};
vector<node> str;
int n,i,L,ans;

signed main(){
	FIN;
	FOU;
	cin>>n;
	char last='0';
	int len=-1;
	for(int i=1;i<=n;i++){
		int a;char b;
		cin>>a>>b;
		L+=b;
		if(b==last){
			len+=a;
		}else{
			if(len>0) str.push_back({last,len});
			last=b;
			len=a;
		}
	}
	str.push_back({last,len});
	n=str.size();
//	printf("n=%lld\n",n);
	if(n==1){
		cout<<0;
		return 0;
	}
	last='0',len=0;int j=n-1;
	for(int i=0;i<n/2;i++){
		int c=str[i].c,l=str[i].l;
//		printf("now:%d %c l=%lld last=%c len=%lld\n",i,c,l,last,len);
		if(last!='0'){
			if(len>l){
				ans+=(c==last?0:l);
				len-=l;
//				printf("check_last last=%c len=%lld ans=%lld\n",last,len,ans);
				continue;
			}else if(len==l){
				ans+=(c==last?0:len);
				len=0,last='0';
//				printf("check_last last=%c len=%lld ans=%lld\n",last,len,ans);
				continue;
			}else{
				ans+=(c==last?0:len);
				len=0,last='0';
				l-=len;
			}
//			printf("check_last last=%c len=%lld ans=%lld\n",last,len,ans);
		}
		for(;j>=0;j--){
//			printf("***j:%d %c l=%lld  ",j,str[j].c,str[j].l);
			if(l>str[j].l){
				ans+=(str[j].c==c?0:str[j].l);
				l-=str[j].l;
//				printf("1 ans=%d l=%d\n",ans,l);
			}else if(l==str[j].l){
				ans+=(str[j].c==c?0:l);
				j--;
//				printf("2 ans=%d l=%d\n",ans,l);
				break;
			}else{
				ans+=(str[j].c==c?0:l);
				last=str[j].c,len=str[j].l-l;
				j--;
//				printf("3 ans=%d l=%d\n",ans,len);
				break;
			}
		}
	}
//	printf("***j:%d %c l=%lld\n",j,str[j].c,str[j].l);
	cout<<ans;
	return 0;
}
