#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct Node{
	int a;
	char c;
};
Node p[200010];
map<char,int> mp;
bool cmp(Node i,Node j){
	if(i.c==j.c)return i.a<j.a;
	return i.c<j.c;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].c;
		//p[i].k+=p[i].a;
		mp[p[i].c]+=p[i].a;
		if(p[i].a!=1&&p[i].a!=0)f=1;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(p[1].c==p[2].c)cout<<0;
		else{
			cout<<min(p[1].a,p[2].a);
		}
		return 0;
	}
	if(f==0){
		int ans=0;
		for(int i=0;i<=25;i++){
			if(mp[char(97+i)]%2==1)ans++;
		}
		cout<<ans/2;
		return 0;
	}
	sort(p+1,p+n+1,cmp);
	char m='a';
	int ans=0,sum=0;
	for(int i=1;i<=n;i++){
		if(p[i].c==m){
			ans+=p[i].a;
			if(ans>mp[m]/2){
				ans=min(ans-mp[m]/2,mp[m]/2+p[i].a-ans);
				sum+=ans;
				while(1){
					
					if(p[i].c==m)i++;
					else break;
					if(i==n+1)break;
				}
				i--;
				m++;
				continue;
			}
		}else{
			m++;
		}
	}
	cout<<sum;
    return 0;
}

