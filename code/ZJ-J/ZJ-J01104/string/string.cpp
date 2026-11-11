#include<bits/stdc++.h>
using namespace std;
struct node{
	int ans;
	char x;
}s[200005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> s[i].ans;
		cin >> s[i].x;
	}
	int l=1,r=n;
	long long cnt=0;
	while(l<r){
		if(s[l].x!=s[r].x){
			if(s[l].ans>s[r].ans){
				cnt+=s[r].ans;
				s[l].ans-=s[r].ans;
				r--;
			}else if(s[l].ans<s[r].ans){
				cnt+=s[l].ans;
				s[r].ans-=s[l].ans;
				l++;
			}else{
				cnt+=s[l].ans;
				l++,r--;
			}
		}else{
			if(s[l].ans>s[r].ans){
				s[l].ans-=s[r].ans;
				r--;
			}else if(s[l].ans<s[r].ans){
				s[r].ans-=s[l].ans;
				l++;
			}else{
				l++,r--;
			}
		}
	}
	cout<<cnt;
	return 0;
}