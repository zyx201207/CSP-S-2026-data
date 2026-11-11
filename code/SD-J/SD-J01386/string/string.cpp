#include<bits/stdc++.h>
#define int long long
using namespace std;
struct size{
	int len;char num;
};
vector<size> f;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,ans=0,total=0;
	cin>>n;
	for(int i=1;i<=n;i++){
	int x;char y;
	cin>>x>>y;total+=x;
	size tmp;tmp.len=x,tmp.num=y;
	f.push_back(tmp);
	}int cnti=0,cntj=total;
	for(int i=0,j=n-1;cnti<cntj&&i!=j;){
		if(f[i].num!=f[j].num){
			if(f[i].len>f[j].len){
				cntj-=f[j].len;cnti+=f[j].len;
				ans+=f[j].len;
				f[i].len-=f[j].len;
				j--;
			}
			else{
				if(f[i].len==f[j].len){
					cntj-=f[i].len;cnti+=f[i].len;
					ans+=f[i].len;
					i++;j--;
				}else{cntj-=f[i].len;cnti+=f[i].len;
					ans+=f[i].len;
					f[j].len-=f[i].len;
					i++;
				}
			}
		}else{
			if(f[i].len>f[j].len){
				cntj-=f[j].len;cnti+=f[j].len;
				f[i].len-=f[j].len;
				j--;
			}
			else{
				if(f[i].len==f[j].len){
					cntj-=f[i].len;cnti+=f[i].len;
					i++;j--;
				}else{
					cntj-=f[i].len;cnti+=f[i].len;
					f[j].len-=f[i].len;
					i++;
				}
			}
		}
	}cout<<ans;
	return 0; 
}

