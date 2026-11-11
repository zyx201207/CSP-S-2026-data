#include<bits/stdc++.h>
using namespace std;
stack<int> l;
const int N=5e5+9;
long long n,m,a[N],num[N];bool CardsNum[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(CardsNum[a[i]]==true){
				while(1){
					if(l.top()==a[i]){
						l.pop();
						break;
					}
					l.pop();
				}
			}l.push(a[i]);
			CardsNum[a[i]]=true;
			if(j==n){
				while(!l.empty()){
					int c=l.top();
					num[c]++;
					l.pop();
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<' ';
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
