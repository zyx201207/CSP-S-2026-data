#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
int v[N];
char ch[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	LL ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>v[i]>>ch[i];
	int l=1,r=n;
	while(l<r){
		if(v[l]<v[r]){
			if(ch[l]!=ch[r]) ans+=v[l];
			v[r]-=v[l];
			l++;
		}else if(v[l]>v[r]){
			if(ch[l]!=ch[r]) ans+=v[r];
			v[l]-=v[r];
			r--;
		}else{
			if(ch[l]!=ch[r]) ans+=v[r];
			r--;
			l++;
		}
	}
	printf("%lld",ans);
	return  0;
}//·´ÎÚÍÐ°î 
