#include<iostream>
#include<queue>
using namespace std;
const int M=2*1e5+100;
int n,m;
long long a[M];
int box[35];
int weishuda=30;//需比对的最大位数 
//int boxn[35][M];
queue <int>q[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	int lena=n;//目前待桶数列长 
	bool b=0;//是否跳出是为1 
	
	while(1){
		for(int i=1;i<=lena;i++){//桶 
			int len=1,x=a[i];
			while(x>0){
				if(x%2==1){
					q[len].push(a[i]);
					box[len]++;
				}
				len++;
				x/=2;
			}
		}
	    
		for(int i=weishuda;i>0;i--){//找到位置or跳出循环 
			if(box[i]>=m){
				weishuda=i;
	    		break;
			}else if(i==1){
				b=1; 
			}
		}
		//判断是否继续
		if(box[weishuda]==m||b==1)break;
		
		for(int i=1;i<=32;i++){//清空 box
			box[i]=0;
		}
		
		lena=q[weishuda].size();
		
		int x;//供转换所用  
		for(int i=1;i<=lena;i++){//转出待桶数列 
			x=q[weishuda].front();			
			a[i]=x;
			q[weishuda].pop();
		}
		
		for(int i=1;i<=32;i++){//清空队列 
			while(!q[i].empty())q[i].pop();
		}
		
	}
	//cout<<weishuda;
	long long ans=q[weishuda].front();
	for(int i=1;i<=m;i++){
		if(q[weishuda].front()){
		
		int x=q[weishuda].front();	
		q[weishuda].pop();	
		ans&=x;
		a[i]=x;
		
		//cout<<x<<" ";
	}
	}
	printf("%lld",ans);
	return 0;
}
