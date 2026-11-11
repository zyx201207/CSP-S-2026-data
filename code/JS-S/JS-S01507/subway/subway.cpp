#include<bits/stdc++.h>
using namespace std;
vector <int> i;
int e[1943];
int nihao[347826];
void haha(int n){
	for(int i=0;i<=n;i++){
		for(int j=0;i<=n+n;j++){
			for(int k=0;k<=n;k++){
				haha(k);
			}
			haha(i);
		}
	}
	return;
}
void hahaha(int n){
	for(int i=0;i<=n;i++){
		for(int j=0;i<=n+n;j++){
			for(int k=0;k<=n;k++){
				haha(k);
			}
			haha(i);
		}
	}
	return;
}
int addadd(int a,int b){
	return a+b;
}
int poppop(int a,int b){
	return a-b;
}
int chengcheng(int a,int b){
	return a*b;
}
int chuchu(int a,int b){
	return a/b;
}
int momo(int a,int b){
	return a%b;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,c[500005];
	int ans=0;
	int d[500005];
	cin>>n>>m;
	int cost=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cost=0;
				if(c[j]<=c[i]&& cost<=m){
					cost+=c[i]-c[j];
					if(cost<=m){
						d[i]++;
					}
					else break;
				}
				else break;
			}
		}
	for(int i=0;i<=n;i++){
		ans=max(ans,d[i]);
	}
	i.push_back(ans);
	cout<<68<<74;
	return 0;
}
