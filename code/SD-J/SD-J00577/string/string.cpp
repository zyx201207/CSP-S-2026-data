#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int a;
	string c;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	int siz=s.size(),to=siz/2;
	for(int i=0;i<to;i++){
		if(s[i]!=s[siz-i-1]){
			ans++;
		}
	}
	cout<<ans;
	/*
	s[0].s=0;
	s[0].e=0;
	s[0].c=' ';
	s[n+1].s=L+1;
	s[n+1].e=L+1;
	s[N+1].c=' ';
	mid=(L+1)/2;
	ts=mid;
	te=mid;
	if(L%2==0){
		te++;
	}
	int l=1,r=n,mid;
	while(l<=r){
		mid=l+r>>1;
		if(s[mid].s<=ts&&s[mid].e>=ts){
			ts_i=mid;
			ts_c=s[mid].c;
			break;
		}
		if(s[mid].s>ts){
			r=mid;
		}else if(s[mid].e<ts){
			l=mid;
		}
	}
	if(ts==s[ts_i].e&&L%2==0){
		te_i=ts_i+1;
		te_c=s[te_i].c;
	}else{
		te_i=ts_i;
		te_c=ts_c;
	}
	while(1){
		if(ts_c==' '||te_c==' '){
			break;
		}
		if(ts_c==te_c){
			//直接跳转
			int ns=s[ts_i].e,ne=s[te_i].s;
			int fixs=mid-ns,fixe=ne-mid;
			if(fixs<fixe){
				//左
				ts=ns-1;
				te=L-ts+1;
				ts_i--;
				ts_c=s[ts_i].c;
				if(s[te_i].e<te){
					te_i++;
					te_c=s[te_i].c;
				}
			}else{
				//右
				te=ne+1;
				ts=L-te+1;
				te_i++;
				te_c=s[te_i].c;
				if(s[ts_i].s>ts){
					ts_i--;
					ts_c=s[ts_i].c;
				}
			}
		}else{
			//记录答案后跳转
			int ns=s[ts_i-1].e,ne=s[te_i+1].s;
			int fixs=mid-ns,fixe=ne-mid;
			if(fixs<fixe){
				//左
				ans+=ts-ns;
				ts=ns;
				te=L-ts+1;
				ts_i--;
				ts_c=s[ts_i].c;
				if(s[te_i].e<te){
					te_i++;
					te_c=s[te_i].c;
				}
			}else{
				//右
				ans+=ne-te;
				te=ne;
				ts=L-te+1;
				te_i++;
				te_c=s[te_i].c;
				if(s[ts_i].s>ts){
					ts_i--;
					ts_c=s[ts_i].c;
				}
			}
		}
	}
	cout<<ans;
	*/
	
	return 0;
}
