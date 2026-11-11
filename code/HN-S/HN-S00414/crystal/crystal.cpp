#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int n,m,ans,num;
vector<int> a;//´Ó0¿ªÊ¼ 
vector<int> c;
int b[N]={0};
int main () {
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n>>m;
	a.resize(0);
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		a.push_back(k);
		c.push_back(0);
	}
	sort(a.begin(),a.end());//ÉýÐò
	int ch=0; 
	int op = 0;
	for(int i=1;i<n;i++){
		int r=i;
		int l=i-1;
		if(op == 1){
			break;
			
		}
		if(a[i]>a[i-1]){
			int cha=a[i]-a[i-1];
			num=0;
			while(l>=ch){
				b[l]+=cha;
				l--;
				if(m>=b[l]){
					m-=b[l];
					b[l]=0;
					if(c[l]==0){
						num++;
						ans++;
						c[l]==1;
					}
				}
				if(m<b[l]&&c[l]==1){
					ans-=num;
					op = 1;
					for(int d=r;d<n;d++){
						if(a[d]==a[d-1])	ans++;
						if(a[d]!=a[d-1])	break;
					}
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
