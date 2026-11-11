#include<bits/stdc++.h>
using namespace std;

long long n,m,crystal[2000010]={};  //crystal存储水晶价格，n为水晶数，m为执行次数 

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long b;
	for(long long a=0;a<n;a++){
		cin>>b;
		b+=1000050;
		crystal[b]++;   //将输入的负数变为正数 
	}
	long long pos=0,epos=0,list=0,mlist=0;
	while(pos<=2000010){
		if(crystal[pos]==0){
			pos++;
			continue;
		}
		long long cal=pos-epos;
		for(long long i=0;i<list;i++){
			m-=cal;
			if(m<0){
				m+=cal;
				list=i;
				break;
			}
			
		}
		list+=crystal[pos];
		if(mlist<list){
			mlist=list;
		}
		epos=pos;
		pos++;
	}
	cout<<mlist;
	return 0;
}
