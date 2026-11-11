#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int cnt,finds,num[N];
int maxn=-1,tmp;
bool comp(int num1,int num2){
	return num1>num2;
}
int max2;
int num2[21]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>cnt>>finds>>num[1];
	for(int i=2;i<=cnt;++i){
		scanf("%d",&num[i]);
		maxn=max(maxn,num[i]);
	}
	if(cnt==finds){
		tmp=num[1];
		for(int i=2;i<=cnt;++i){
			tmp&=num[i];
		}
		cout<<tmp;
		return 0;
	} 
	else if(finds==1){
		cout<<maxn;
	}
	else if(cnt==finds+1){
		bool flag=1;
		for(int i=1;i<=cnt;++i){
			for(int j=20;j>=0;--j){
				if(num[i]==num2[j]){
					max2=max(max2,num2[j]);
				}
			}
		}
		for(int i=1;i<=cnt;++i){
			if(num[i]==max2){
				if(i!=cnt){
					num[i]=num[i+1];
				}
				else num[i]=num[i-1];
				break;
			}
		}
		tmp=num[1];
		for(int i=2;i<=cnt;++i){
			tmp&=num[i];
		}
		cout<<tmp;
	}
	else{
		sort(num+1,num+cnt+1,comp);
		cout<<num[finds];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

