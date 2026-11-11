#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
vector<int> desk;
bool in[300005];

int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	
	for(int i=1;i<=n;i++){
		//printf("\033[34m1\033[0m");
		
		for(int j=i;j<=n;j++){
			if(in[a[j]]){
				
				while(true){
					if(desk.back()==a[j] ){
						in[desk.back()]=false;
						desk.pop_back();
						
						break;
					}
					else{
						in[desk.back()]=false;
						desk.pop_back();
					}
				}
				in[a[j]]=false;
			}
			in[a[j]]=true;
			desk.push_back(a[j]);
			
		}
		for(int j=0;j<(int)desk.size();j++){
			//cout<<desk[j]<<' ';
			cnt[desk[j]]++;
			in[desk[j]]=false;
		}
		//cout<<endl;
		desk.clear();
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
		//cout<<cnt[i]<<' ';
	}
		/*
10 3
3 1 2 1 3 2 3 1 2 1

4 3
1 2 1 3*/
	return 0;
}
