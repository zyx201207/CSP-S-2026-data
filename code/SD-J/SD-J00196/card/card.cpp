#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],mi[300010];
void fc(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
}
int main(){
	fc();
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int l=1;l<=n;l++){//局数 
		stack<int> s;
		for(int i=l;i<=n;i++){//插牌 
			bool flag=true;
			int id;
			for(int j=l;j<i&&flag;j++){//判断是否出现过 
				if(a[j]==a[i]){
					flag=false;
					id=i-j;
				}
			} 
			if(flag==false){//删除
				while(id--) s.pop();
			}
			s.push(a[i]);
		}
		while(!s.empty()){
			int p=s.top();
			s.pop();
			mi[p]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<mi[i]<<" ";
	return 0;
} 
