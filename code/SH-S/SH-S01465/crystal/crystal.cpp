#include <iostream>
#include<math.h>
using namespace std;
int n,m;
int engy[50050];
int dis[50050];
int check=0,rep=0,extra,lim1=0,lim2=0,result,final=0;
int ans[50050];
int flag[50050];
int copy1[50050];

int dfs(int i){
	int k=m;
	int num=0;
	for(int j=i;j>=1;j--){
		if(engy[i]>=engy[j] && k>=engy[i]-engy[j]){
			k=k-engy[i]+engy[j];
			engy[j]=engy[i];
			num++;
		}
	}
	return num;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>engy[i];
	}
	for(int i=1;i<n;i++){
		for(int i=1;i<n;i++){
			if(engy[i]>engy[i+1]){
				int temp=engy[i];
				engy[i]=engy[i+1];
				engy[i+1]=temp;
			}
		} 
	}
	for(int i=1;i<=n;i++){
		copy1[i]=engy[i];
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++){
			engy[i]=copy1[i];
		}
		result=dfs(i);
		//cout<<result;
		/*for(int i=1;i<=n;i++){
			cout<<engy[i];
		}*/
		ans[i]=result; 
	}
	/*for(int i=1;i<=n;i++){
		cout<<ans[i];
	}*/
	for(int i=1;i<=n;i++){
		final=max(ans[i],final);
	}
	cout<<final;
	return 0;
}
