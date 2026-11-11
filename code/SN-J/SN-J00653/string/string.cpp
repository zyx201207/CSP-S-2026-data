//姜承宇 西安翱翔中学 SN-J00653
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct jcy{
	int a;
	char c;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	int l = 1,r = n,cnt = 0;
	while(l<=r){
		char c1 = a[l].c,c2 = a[r].c;
		if(c1 == c2){
			if(a[l].a!=a[r].a){
				if(a[l].a>a[r].a){
					a[l].a = a[l].a-a[r].a;
					r--;
				}else{
					a[r].a = a[r].a-a[l].a;
					l++;
				}
			}else{
				l++,r--;
			}
		}else{
			if(a[l].a!=a[r].a){
				if(a[l].a>a[r].a){
					a[l].a = a[l].a-a[r].a;
					cnt+=a[r].a;
					r--;
				}else{
					a[r].a = a[r].a-a[l].a;
					cnt+=a[l].a;
					l++;
				}
			}else{
				cnt+=a[l].a;
				l++,r--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
