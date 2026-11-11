#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct NODE{
	int num;
	char c;
}a[N],st,en;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,lent=0;
	cin>>n;
	long long b,tot=0,len=0,ans=0,elen=0;
	string s;
	char s1;
	for(int i=1;i<=n;++i){
		cin>>b>>s1;
		a[++lent].num=b;
		a[lent].c=s1;
		tot+=b;
	}
	tot=(tot+1)/2;
	for(int i=1,j=n;len<=tot&&j>=1&&elen<=tot;++i){
		len+=a[i].num;
		if(len>tot) break;
		st.num+=a[i].num;
		st.c=a[i].c;
		if(en.num==0){
			en.num+=a[j].num;
			en.c=a[j].c;
			j--;
			elen+=a[j].num;
		}
		while(st.c==en.c&&st.num>=en.num){
			if(elen+a[j].num>=tot){
				break;
			}
			st.num-=en.num;
			en.num=a[j].num;
			en.c=a[j].c;
			j--;
			elen+=a[j].num;
		}
		if(st.c==en.c&&st.num<en.num){
			if(st.c!=en.c) ans+=st.num;
			en.num-=st.num;
			st.num=0;
		}
		if(st.c!=en.c){
			ans+=st.num;
			en.num-=st.num;
			st.num=0;
		}
	}
	cout<<ans;
	return 0;
}
