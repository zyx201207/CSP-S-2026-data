#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
long long len=0;
long long ans=0;
struct node{
	int siz;
	char c;
}a[1000010],b[1000010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].siz>>a[i].c;
		len+=a[i].siz;
	}
	if(len%2==1){
		int cnt=0;
		int j=1;
		while(cnt<=len/2+1){
			cnt+=a[j].siz;
			j++; 
		}
		j--;
		cnt-=a[j].siz;
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(i!=j&&!flag){
				b[i].siz=a[i].siz;
				b[i].c=a[i].c;
			}
			else if(flag){
				b[i+1].siz=a[i].siz;
				b[i+1].c=a[i].c;
			}else if(i==j){
				b[i].siz=(len/2+1-cnt);
				b[i].c=a[i].c;
				b[i+1].siz=a[i].siz-(len/2+1-cnt);
				b[i+1].c=a[i].c;
				flag=1;
			}
		}
		ans=0;
		int l=1,r=n+1;
		while(l<=r){
			if(b[l].siz>b[r].siz){
				if(b[l].c==b[r].c){
					b[l].siz-=b[r].siz;
					r--;
				}else{
					ans+=b[r].siz;
					b[l].siz-=b[r].siz;
					r--;
				}
			}
			else if(b[l].siz<b[r].siz){
				if(b[l].c==b[r].c){
					b[r].siz-=b[l].siz;
					l++;
				}else{
					ans+=b[l].siz;
					b[r].siz-=b[l].siz;
					l++;
				}
			}
			else if(b[l].siz==b[r].siz){
				if(b[l].c==b[r].c){
					l++;
					r--;
				}else{
					cnt+=b[l].siz;
					r--;
					l++;
				}
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			b[i].siz=a[i].siz;
			b[i].c=a[i].c;
		}
		ans=0;
		int l=1,r=n;
		while(l<=r){
			if(b[l].siz>b[r].siz){
				if(b[l].c==b[r].c){
					b[l].siz-=b[r].siz;
					r--;
				}else{
					ans+=b[r].siz;
					b[l].siz-=b[r].siz;
					r--;
				}
			}
			else if(b[l].siz<b[r].siz){
				if(b[l].c==b[r].c){
					b[r].siz-=b[l].siz;
					l++;
				}else{
					ans+=b[l].siz;
					b[r].siz-=b[l].siz;
					l++;
				}
			}
			else if(b[l].siz==b[r].siz){
				if(b[l].c==b[r].c){
					l++;
					r--;
				}else{
					ans+=b[l].siz;
					r--;
					l++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

