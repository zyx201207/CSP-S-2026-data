#include<bits/stdc++.h>
using namespace std;
struct p{
	long long num;
	char c;
}a[200005],b[200005];
int n;
int tot;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		++tot;
		b[tot].c=a[i].c;
		while(a[i].c==a[j].c&&j<=n){
			b[tot].num+=a[j].num;
			j++;
		}
		i=j-1;
		//cout<<b[tot].c<<' '<<b[tot].num<<'\n';
	}
	int l=1,r=tot;
	long long ans=0;
	while(l<r){
		if(b[l].c==b[r].c){
			if(b[l].num<b[r].num){
			    b[r].num-=b[l].num;
				l++;
			}else if(b[r].num<b[l].num){
			    b[l].num-=b[r].num;
				r--;
			}else{
				l++;
				r--;
			}
		}else{
			if(b[l].num<b[r].num){
			    b[r].num-=b[l].num;
				ans+=b[l].num;
				l++;
			}else if(b[r].num<b[l].num){
			    b[l].num-=b[r].num;
				ans+=b[r].num;
				r--;
			}else{
				ans+=b[r].num;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
// string.out string6.ans
