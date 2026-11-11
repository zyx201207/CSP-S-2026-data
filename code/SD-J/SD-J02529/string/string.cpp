#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	char let;
}a[200010];
struct no{
	int num;
	char let;
}b[200010];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i].num,&a[i].let);
		b[n+1-i].num=a[i].num;
		b[n+1-i].let=a[i].let;
	}
	int x,cnt=0;
	char c;
	for(int i=1,j=1;i<=n;i++){
		if(a[i].num==b[j].num&&a[i].let==b[j].let){
			j++;
			continue;
		}
		if(a[i].num==b[j].num&&a[i].let!=b[j].let){
			x=a[i].num;
			cnt+=x;
			j++;
			continue;
		}
		if(a[i].let==b[j].let){
			if(a[i].num>b[j].num){
				a[i].num-=b[j].num;
				i--;
			}else{
				b[j].num-=a[i].num;
				j--;
			}
		}else{
			if(a[i].num>b[j].num){
				x=a[i].num-b[j].num;
				cnt+=x;
				a[i].num=x;
				i--;
			}else{
				x=b[j].num-a[i].num;
				cnt+=x;
				b[j].num=x;
				j--;
			}
		}
		j++;
	}
	printf("%d",cnt/2);
	return 0;
}
