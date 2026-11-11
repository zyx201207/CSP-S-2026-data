#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],maxnum,s,i,j,flag,w,d;
typedef long long ll;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	flag=m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		maxnum=max(a[i],maxnum);
	}
	if(m==1){
		cout<<maxnum;
		return 0;
	}
	while(m>0){
		if(m==flag){
			sort(a+1,a+n+1,cmp);
			for(j=1;j<=n;j++){
				for(w=j+1;w<=n;w++){
					if(((a[j]&(a[j]-1))!=0)&&((a[w]&(a[w]-1))!=0)){
						a[j]=a[j]&a[w];
						d=a[1];
						a[1]=a[j];
						a[j]=d;
						a[w]=0;
						break;
					}
					else
						continue;
				}
				if(w<n){
					 break;
					 }
			}
		}
		else{
			sort(a+2,a+n+1,cmp);
			for(s=2;s<=n;s++){
				if(a[s]&(a[s]-1)!=0){
					a[1]=a[1]&a[s];
					a[s]=0;
				}
			}
		}
		m--;
	}
	cout<<a[1];
}

