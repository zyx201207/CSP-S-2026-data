#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	//freopen!
	int c,t;
	cin >> c>>t;
	int cut[100000]=0;
	int b=0;
	int n,d;
	int m=0;//
	int p=0;//表示每段有几个 
	int max=0;//表示最大的
	int f=0;//等会可能用 
	int a=0;
	for (int i=0;i<t;i++){//循环 
		cin >> n>>d;
		for (int j=0;j<n;j++){
			int x[j];
			cin >> x[j];
		}
		//先排除飞不过去的情况
		for (int j=1;j<n;j++){
			if (x[j]-x[j-1]>d){
				cut[b]=j-1;//后面的都不用考虑了 
				b++;
			}
			for (int k=j+1;k<cut[1];k++){//准备挨个考虑 
				if ((x[k]-x[j])/d==f){
					p+=1;
					if (p>2){
						max=x[k-2];
					}
				}else{
					for (int u=k;u<=cut[1];u++){
						if(cut[1]<max){
							break;//直接不用考虑了，这段都没有 
						}
						if(x[u]>max){//此时x[j]~x[u]全都不用考虑了，一定没有 
							k=u+1;
							p=0;
							f=0;
						}
					}
				} 
				f+=1;	
			} 
		}
	return 0;
}
