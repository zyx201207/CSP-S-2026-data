#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[1000010],len,s,cnt,s1,lj,ls,f,sum;
ll ans;
string s2;
char c[1000010],bz;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=2000){
		for(ll i=1;i<=n;i++){
		    cin>>a[i]>>c[i];
		    for(ll j=1;j<=a[i];j++){
			    s2=s2+c[i];
		    }
	    }
	    len=s2.size();
	    for(ll i=0;i<len/2;i++){
		    if(s2[i]!=s2[len-1-i]){
			    ans++;
		    }
	    }
	    cout<<ans;
	}else{
		for(ll i=1;i<=n;i++){
			cin>>a[i]>>c[i];
			len+=a[i];
			a[i]=len;
		}
		if(len%2==1)f=1;
		s=len;
		len=len/2;
		ll l=0,r=n;
		while(a[l]<len){
			if(a[l+1]<=len){
				cnt=a[l+1]-a[l];
				bz=c[l+1];
			}else{
				cnt=len-a[l];
				bz=c[l+1];
			}
			l++;
			s1=s;
			s-=cnt;
			//cout<<s<<"\n";
			while(s1>s){
				if(a[r-1]>s){
					if(c[r-1]!=bz){
						ans+=a[r]-a[r-1]-ls;
					}
					ls=0;
					s1=a[r-1];
					r--;
				}else{
					lj=s1-s;
					ls+=lj;
					s1=s;
					if(c[r]!=bz){
						ans+=lj;
					}
				}
			}
			//cout<<ans<<"\n";
		}
		cout<<ans;
	}
}
//J gua le,S jiu bie rang wo gua le ba. qwq
