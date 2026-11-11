/*#include <bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
	int num1[31];
	int a;
	int vis=1;
};
Node v[200005];
int a[200005];
int ma=0;
void er(int x,int i){//二进制函数 
	int cnt=0;
	while(x!=0){
		int gw=x%2;
		x/=2;
		v[i].num1[cnt]=gw;
		if(cnt>ma){
			ma=cnt;
		}
	}
} 
int s[200005];
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i].a;
		er(v[i].a ,i);
	}
	for(int j=ma;j>=1;j--){
		int c=0;
		for(int i=1;i<=n;i++){
			if(v[j].num1[ma]==1){
				c++;	
			}
		}
		if(c<m){
			continue;
		}
		for(int i=1;i<=n;i++){
			if(v[j].num1[ma]==1){
				v[j].vis =0;	
			}
		}
	}
	int cc=0;
	for(int i=1;i<=n;i++){
		if(v[i].vis ==1){
			cc++;
			for(int j=1;j<=30;j++){
				s[cc]+=int(pow(v[i].num1[j]*2,j-1));
			}
		}
	}
	int sum=s[1];
	for(int i=2;i<=m;i++){
		sum&=s[i];
	}
	cout<<sum;
	return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int sum=a[1];
	for(int i=2;i<=m;i++){
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
