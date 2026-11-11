//SN-J00564
//long long !
#include <bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char c;
}a[200010],b[200010],ls[200010];
int n,cnt=0,m1,m2;
long long ans=0;
int pos1=1,pos2=1;
long long s1=0,s2=0;
long long sum=0;//所有数量总和 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		char ci;
		cin >> x >> ci;
		sum+=x;
		if(ls[cnt].c==ci){
			ls[cnt].num+=x;
		}else{
			cnt++;
			ls[cnt].num=x;
			ls[cnt].c=ci;
		}
	}
	long long t=0;
	for(int i=1;i<=cnt;i++){
		t+=ls[i].num;
		if(t<=sum/2){
			a[i].num=ls[i].num;
			a[i].c=ls[i].c;
		}else{
			if(sum/2-(t-ls[i].num)==0){
				m1=i-1;
				break;
			}
			a[i].num=sum/2-(t-ls[i].num);
			a[i].c=ls[i].c;
			m1=i;
			break;
		}
	}
	t=0;
	//cout << sum << endl;
	for(int i=cnt;i>=1;i--){
		t+=ls[i].num;
		//cout << t << endl;
		int j=cnt-i+1;
		if(t<=sum/2){
			b[j].num=ls[i].num;
			b[j].c=ls[i].c;
		}else{
			if(sum/2-(t-ls[i].num)==0){
				m2=j-1;
				break;
			}
			b[j].num=sum/2-(t-ls[i].num);
			b[j].c=ls[i].c;
			m2=j;
			break;
		}
	}
	/*
	cout << m1 << endl;
	for(int i=1;i<=m1;i++){
		printf("%lld %c\n",a[i].num,a[i].c);
	}
	cout << m2 << endl;
	for(int i=1;i<=m2;i++){
		printf("%lld %c\n",b[i].num,b[i].c);
	}
	*/
	s1=a[1].num,s2=b[1].num;
	while(pos1<=m1 && pos2<=m2){
		//答案加上两区间的交集的长度 
		if(a[pos1].c!=b[pos2].c){
			//s1-a[pos1]+1到s1
			//s2-b[pos2]+1到s2 
			long long l=max(s1-a[pos1].num+1,s2-b[pos2].num+1);
			long long r=min(s1,s2);
			ans+=r-l+1;
		}
		if(s1>s2){
			pos2++;
			s2+=b[pos2].num;
		}else if(s1==s2){
			pos1++,pos2++;
			s1+=a[pos1].num;
			s2+=b[pos2].num;
		}else{
			pos1++;
			s1+=a[pos1].num;
		}
	}
	printf("%lld",ans);
	return 0;
}
