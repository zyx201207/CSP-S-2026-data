
#include<bits/stdc++.h>

using namespace std;
int tick[500010],num[300010],sign[300010][2];
int zh[500010],t=1;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>tick[i];
	}
	for(int k=1;k<=n;k++){
		t=1;
		for(int i=k;i<=n;i++){
			zh[t++]=tick[i];
			if(sign[tick[i]][1]%2==1){
				t=sign[tick[i]][0];
			}
			if(sign[tick[i]][1]%2==0)sign[tick[i]][0]=t;
			sign[tick[i]][1]+=1;
		}
		for(int i=1;i<t;i++){
			num[zh[i]]+=1;
		}
    }
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
