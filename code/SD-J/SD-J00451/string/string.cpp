#include<bits/stdc++.h>
using namespace std;
int n; 
struct node{
	long long num;
	char c;
};
node a[200050];
int cnt=0;
long long all=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){ //合并 
		int numx; 
		char cx;
		cin>>numx>>cx;
		if(cx==a[cnt].c){
			a[cnt].num+=numx;
			//cout<<1;
		} 
		else{
			cnt++;
			a[cnt].num=numx;
			a[cnt].c=cx;
		}
	} 
	//for(int i=1;i<=cnt;i++) cout<<a[i].num<<" "<<a[i].c<<" "<<i<<endl;
	int l=1,r=cnt;
	while(l<=r){
		if(a[l].num<=a[r].num){
			long long sum=0;
			long long sumx=0; //实际改了多少个 
			sum=a[r].num;
			
			for(int i=l;i<r;i++){
				//if(a[i].c==a[l].c) all=max(all-a[i].num,0); //遇到相同的 不用变 
				if(a[i].num>=sum){
					if(a[i].c!=a[r].c) sumx+=sum;
					a[i].num-=sum;
					sum=0;
					l=i;
					break;
				}
				else{
					if(a[i].c!=a[r].c) sumx+=a[i].num;
					sum-=a[i].num;
					a[i].num=0;
				}
			}
			//cout<<sumx<<endl;
			all+=sumx;
			if(sum==0) r--;
			else break;
		}	
		else{
			long long sum=0;
			long long sumx=0; //实际改了多少个 
			sum=a[l].num;
			
			for(int i=r;i>l;i--){
				//if(a[i].c==a[l].c) all=max(all-a[i].num,0); //遇到相同的 不用变 
				if(a[i].num>=sum){
					if(a[i].c!=a[l].c) sumx+=sum;
					a[i].num-=sum;
					sum=0;
					r=i;
					break;
				}
				else{
					if(a[i].c!=a[l].c) sumx+=a[i].num;
					sum-=a[i].num;
					a[i].num=0;
				}
			}
			//cout<<sumx<<endl;
			all+=sumx;
			if(sum==0) l++;
			else break;
		}
		//for(int i=1;i<=cnt;i++) cout<<a[i].num<<" "<<a[i].c<<endl;
		//cout<<endl;
	}
	cout<<all;
	return 0;
} 
/*
6
3 c
5 b
4 c
4 a
1 b
6 a
*/
