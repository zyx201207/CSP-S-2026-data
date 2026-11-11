#include<iostream> 
using namespace std;
long long n,tmp,cnt=0,count=0;
char char_;
char lst[1000005]={0};
long long p,p1;
int main(){
	freopen("string3.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long i=0;i<n;i++){
		cin>>tmp;
		cin>>char_;
		for(long j=0;j<tmp;j++){
			lst[cnt]=char_;
			cnt++;
		}
	}
	if((cnt)%2==1){
		p=(cnt-1)/2;   

		for(long i=1;i<=cnt-1;i++){
			if(lst[p+i]!=lst[p-i]){//0 1 2 3 4
				count++;
			}
		}
		cout<<count;
	}
	else{
		p=cnt/2-1;
		p1=p+1;
		for(long i=0;i<=cnt/2;i++){
			if(lst[p-i]!=lst[p1+i]){
				count++;
			}
		}
		cout<<count; 
	}
}

/*               
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
