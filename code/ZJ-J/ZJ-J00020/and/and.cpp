#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,m,a[maxn];
vector<int>tmp[2];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	

	
	int y=2,x=0,cnt=0;
	while(y<=(a[n]/2))y<<=1;

	while(y){
		int i=n;
		while(i>=1){
			int num=a[i]&y;
			if(num<y)break;
			i--;
		}
		


		if(i<n-m+1){
			x+=y;
			for(int j=n;j>i;j--)tmp[0].push_back(a[j]);
			break;
		}
		y/=2;
	}
	vector<int>::iterator it;
	bool flag=0;
	

	y/=2;
	while(y){
		cnt=0;

		it=tmp[flag].begin();
		for(;it<=tmp[flag].end()-1;it++){
			if(((*it)&y)==y){
				tmp[!flag].push_back(*it);
				cnt++;
			}
		}
		

		
		if(cnt>=m){
			tmp[flag].clear();
			flag=!flag;
			x+=y;
		}
		else {
			tmp[!flag].clear();
		}
		y/=2;
	}
	cout<<x;
	return 0;
}