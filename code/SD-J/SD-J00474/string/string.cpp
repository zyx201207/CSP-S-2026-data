#include <iostream>
#include <cstring>

using namespace std; 

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,mid=0,count=0;
	int put;
	char zi;
	int num[200010];
	char z[200010];
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> put >>zi;
		for(int j=1+sum;j<=put+sum;j++){
			z[j]=zi;		
		}
		sum+=put;
	}
	if (sum % 2 == 0){
		mid=sum/2;
		for(int i=1;i<=mid;i++){
			if(z[mid+1-i]!=z[mid+i]){
				count+=1;
			}
		}
	}
	else{
		mid=sum/2 +1;
		for(int i=1;i<mid;i++){
			if(z[mid-i]!=z[mid+i]){
			count+=1;
			}
		} 
	}
	cout << count;
	return 0;
	
	
}
