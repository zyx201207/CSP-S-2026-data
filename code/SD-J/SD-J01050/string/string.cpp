#include<bits/stdc++.h>
using namespace std;
long long n,cnt=1;
long long sum,len=0;
struct node{
	char id;
	long long count=0;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char st;
		cin>>sum>>st;
		len+=sum;
		if(i==1){
			a[cnt].id=st;
			a[cnt].count=sum;
			continue;
		}
		if(st==a[cnt].id){
			a[cnt].count+=sum;
		}else{
			a[++cnt].id=st;
			a[cnt].count=sum;
		}
	}
//	for(int i=1;i<=cnt;i++){
//		cout<<a[i].count<<" "<<a[i].id<<"\n";
//	}//             自测个数

//    cout<<cnt<<"\n";     //cnt
//  	cout<<len;
	int fff1=1,fff2=cnt;//当前在哪个区间   
	long long cntt=0;//计数，要变都少次 
	long long summ=1,summ2=len;//当前在哪
	long long leng=len/2;
	while(summ<=leng&&summ2>=len-leng){
		long long minn=min(a[fff1].count,a[fff2].count);
		summ+=minn,summ2-=minn;
		if(fff1==fff2){
			break;
		}
		a[fff1].count-=minn,a[fff2].count-=minn;
		if(a[fff1].id!=a[fff2].id){
			cntt+=minn;
		}if(a[fff1].count==0){
			fff1++;
		}if(a[fff2].count==0){
			fff2--;
		}
	}
	cout<<cntt;
	return 0;
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



































//我真服了旁边那个你别吵了别看了 
