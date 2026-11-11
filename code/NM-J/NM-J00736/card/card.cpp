#include<bits/stdc++.h>
using namespace std;

int pai[100005];
int desk[100005] = {-1};
bool vis [100005] = {0};
int now = 0;
int js[100005] = {0};

	
void clean(int a){
	//ÀÏ×æ¾ÈÎÒß÷~~ 
//	cout<<"clean is running!"<<a<<endl;
	while(1){
		if(desk[now]==a) break;
		int tmp = desk[now];
		vis[tmp] = 0;
		desk[now] = -1;
		now--;
		
	}
	return;
}


int main(){

//    cout<<"freopen file name"<<endl;

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

	int n,m;
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++){	
		cin>>pai[i];
		js[pai[i]]++;
	} 
	
	
	
	
	//int ans[30005] = {0};
	
	
	
	int ans[m+2] = {0};
	
	for(int i=0;i<n;i++){  //jv shu 
		
		for(int j=i;j<n;j++){   //da pai

			

			if(vis[pai[j]]){
				if(js[pai[j]]>=20){
					int adf;
					for(int x = j+18;j<n;j++){
						if(pai[x]!=pai[x+1]){
							now += x-j-1;
							adf = x;
							break;
						}
					}
					
					clean(pai[adf]); 
				}
				
				else clean(pai[j]); 				//xiao huo che clean pai
			}
			
			
			
			desk[now] = pai[j];
			now++;
			vis[pai[j]] = 1;
			
		//	cout<<now<<endl;for(int o=0;o<now;o++){cout<<desk[o]<<' ';}cout<<endl;
		}
		
		
		
		
	//	for(int o=0;o<now;o++){cout<<desk[o]<<' ';}cout<<endl;
		
		
		
		
		for(int j=0;j<now;j++){
			ans[desk[j]]++;
			vis[desk[j]] = 0;
			desk[j] = -1;
			
			
		}
		now = 0;
	//	for(int o=0;o<10;o++){cout<<desk[o]<<' ';}cout<<endl;
		
		//cout<<"+++++++++out+++++++++"<<endl;
		
		
	}
	
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	

	

    return 0;
}
