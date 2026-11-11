#include <bits/stdc++.h>
using namespace std;
int nn[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>nn[i];
		
	}
	if(n<=5&&m<=2){
		int j;
		for(j=0;j<5;j++){
				//int tmp[6];
		//int k = nn[i];
		//if(nn[i+1]!=k&&nn[i+2]!=k&&nn[i+3]!=k&&nn[i+4]!=k)nn[5] = k;
		/*else{
			for(int i=1;i<5;i++){
				if(nn[i]==k){
					nn[i+1] = nn[i+2]=nn[i+3] = nn[i+4]=nn[i+5] = 0;
				}			
			}

		} */	
		}
		cout<< j<<" "<<m;

	}
	queue<int> que;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			que.push(nn[j]);
		}
		bool is = false;
		for(int j=i;j<n;j++){
			int k;
			/*for(k=0;k<que.size();k++){
				if(que[k]==nn[j])is = true;
			}*/
			int left,right;
			if(is){
		
				que.push(nn[j]);
				for(int l=j;l<k;l++){
					
				}
			}
			else que.push(nn[j]);
			if(que.empty()){
				for(int k=0;k<n;k++){
					
				}
			}
		}
		
	}
	return 0;
}

