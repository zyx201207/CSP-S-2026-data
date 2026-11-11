#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],cnt[35],maxb;
vector<int>vec[35];
map<pair<int,int>,bool>mp;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=30;i++){
		for(int j=1;j<=n;j++){
			if(a[j]&(1<<i)){
				vec[i].push_back(j);
				mp[make_pair(i,j)]=true;
				cnt[i]++;
			}
		}
	}
	for(int i=30;i>=1;i--){
		if(cnt[i]>=m){
			maxb=i;
			break;
		}
	}
	if(maxb==0){
		cout<<1<<endl;
		return 0;
	}
	int lstout=a[vec[maxb][0]];
	for(int i:vec[maxb]){
		lstout&=a[i];
	}
	if(cnt[maxb]==m){
		cout<<lstout<<endl;
	}else{
		set<int>s;
		for(int i:vec[maxb]){
			s.insert(i);
		}
		while(true){
			int lstoutt=INT_MAX;
			if(s.size()>=m){
				for(int i:s){
					lstoutt&=a[i];
				}
			}
			lstout=lstoutt;
			if(s.size()==m||maxb==0){
				cout<<lstout<<endl;
				return 0;
			}
			for(int i=maxb-1;i>=0;i--){
				int cnta;
				for(int j:s){
					if(a[j]&(1<<i)){
						cnta++;
					}
				}
				maxb=i;
				set<int>c;
				c=s;
				for(int k:s){
					if(!(a[k]&(1<<i))){
						c.erase(k);
					}
				}
				if(c.size()>=m){
					s=c;
					break;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}