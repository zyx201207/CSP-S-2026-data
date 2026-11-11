#include<bits/stdc++.h>
using namespace std;
char s[200005],ls,rs;
long   m[200005],n,l,r,ln,rn,a=1,b;
long long ans=0,sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i];
		cin>>s[i];
	}
	l=m[1];
	r=m[n];
	ls=s[1];
	rs=s[n];
	b=n;
	while(a!=b){
		if(ls==rs){
			l-=r;
			r-=l;
			m[a]-=m[b];
			m[b]-=m[a];
			if(l<=0){
                m[a]=0;
				l=m[a++];
				ls=s[a];
			}
			if(r<=0){
			    m[b]=0;
				r=m[b--];
				rs=s[b];
			}
			continue;
		}
		if(l==r){
			ans+=l;
			m[a]=0;
			m[b]=0;
			l=m[a++];
			ls=s[a];
			r=m[b--];
			rs=s[b];
			continue;
		}
		if(l>r){
			l-=r;
			m[a]-=m[b];
			m[b]=0;
			ans+=r;
			r=m[b--];
			rs=s[b];
		}
			else{
            m[b]-=m[a];
            m[a]=0;
			r-=l;
			ans+=l;
			r=m[b];
			rs=s[b];
		}
	}
	cout<<ans;
    return 0;
}
