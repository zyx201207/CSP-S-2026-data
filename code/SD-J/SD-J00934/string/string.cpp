#include<bits/stdc++.h>
using namespace std;
long long ans;
struct node{
	long long a;
	char c;
}s[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	long long l=1,r=n;
	while(l<r){
		if(s[l].c==s[r].c&&s[l].a==s[r].a){
			l++,r--; 
		}else if(s[l].a==s[r].a&&s[l].c!=s[r].c){
			ans+=s[l].a;
			l++,r--;
		}else if(s[l].a!=s[r].a&&s[l].c==s[r].c){
			if(s[l].a>s[r].a){
				s[l].a-=s[r].a;
				r--;
			}else{
			    s[r].a-=s[l].a;
			    l++;
		    }
		}else{
			ans+=min(s[l].a,s[r].a);
			if(s[l].a>s[r].a){
				s[l].a-=s[r].a;
				r--;
			}else{
			    s[r].a-=s[l].a;
			    l++;
		    }
		}
	}
	cout<<ans;
	return 0;
}
