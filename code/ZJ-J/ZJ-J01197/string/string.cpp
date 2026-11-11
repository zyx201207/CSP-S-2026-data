#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=2e5+10;
ll a[N],n,maxx;
char c[N];
string re(char a,ll b){
    string sum="";
    for(int i=1;i<=b;i++){
        sum+=a;
    }
    return sum;
}
map<int,pair<char,ll> > mp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		maxx=max(maxx,a[i]);
		if(c[i]==c[i-1]){
			mp[cnt].se+=a[i];
		}else{
			mp[++cnt].fi=c[i],mp[cnt].se=a[i];
		}
	}
	if(cnt==1){
		cout<<0;
		return 0;
	}
	if(maxx<=50){
        string a="";
        for(int i=1;i<=cnt;i++){
            a=a+re(mp[i].fi,mp[i].se);
        }
        string s=a;
        ll ans=0;
        reverse(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
            if(s[i]!=a[i]) ans+=1;
        }
        cout<<ans/2;
        return 0;
    }
    ll l=1,r=n,cntl=0,cntr=cnt+1,ans=0;
	while(cntl+1<cntr-1){
		l=mp[++cntl].se;
		r=mp[--cntr].se;
		if(l==r){
			if(mp[cntl].fi==mp[cntr].fi){
				continue;
			}else{
				ans+=l;
			}
		}else{
		    bool flag=0;
			ll sum=0;
			if(l>r){
				sum=r;
				while(l>sum){
                    //cout<<cntl<<" "<<cntr<<" "<<l<<" "<<sum<<" "<<mp[cntl].fi<<" "<<mp[cntr].fi<<" 33333\n";
					//if(cntl==8) return 0;
					if(mp[cntl].fi!=mp[cntr].fi){
					    ans+=r;
					}
					r=mp[--cntr].se;
					sum+=r;
					if(cntr==cntl) flag=1;
                    //cout<<sum<<" "<<ans<<" 44444\n";
				} if(flag) break;
				if(l<sum){
					if(mp[cntl].fi==mp[cntr].fi){
						mp[cntr++].se=sum-l;
						//cout<<l<<" "<<r<<" "<<ans<<" 777777\n";
						continue;
					}else{
						ans+=l-sum+r;
						mp[cntr++].se=sum-l;
						//cout<<l<<" "<<r<<" "<<ans<<" 777777\n";
						continue;
					}
				}else{
                    if(mp[cntl].fi!=mp[cntr].fi) ans+=r;
                    //cout<<l<<" "<<r<<" "<<ans<<" 777777\n";
				}
			}else{
				sum=l;
				while(r>sum){
                    //cout<<cntl<<" "<<cntr<<" "<<r<<" "<<sum<<" "<<mp[cntl].fi<<" "<<mp[cntr].fi<<" 55555\n";
					if(mp[cntl].fi!=mp[cntr].fi){
                        ans+=l;
					}
					l=mp[++cntl].se;
					sum+=l;
					if(cntr==cntl) flag=1;
                    //cout<<sum<<" "<<ans<<" 66666\n";
				}if(flag) break;
				if(r<sum){
					if(mp[cntl].fi==mp[cntr].fi){
						mp[cntl--].se=sum-r;
						//cout<<l<<" "<<r<<" "<<ans<<" 888888\n";
						continue;
					}else{
						ans+=r-sum+l;
						mp[cntl--].se=sum-r;
						//cout<<l<<" "<<r<<" "<<ans<<" 888888\n";
						continue;
					}
				}else{
                    if(mp[cntl].fi!=mp[cntr].fi) ans+=l;
                    //cout<<l<<" "<<r<<" "<<ans<<" 888888\n";
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
//140700461 j
//988433303 s
