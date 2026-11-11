#include<bits/stdc++.h>
using namespace std;
unsigned int n=0,n_,index,j; unsigned long long length=0,a[200010]={},a_[200010]={},result=0; char c[200010]={},c_[200010]={}; string input;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(false);
	cin>>n;n_=n;index=1;
	for (unsigned int i=1;i<=n;i++){
		cin>>a[i]>>c[i]; length+=a[i];
		for (unsigned long long t=0;t<a[i];t++) input+=c[i];
		/*下为优化版记录数组
		if (i<j) continue;
		c_[index]=c[i];a_[index]=a[i];j=1;
		for (j=i;j<=n&&c[j]==c[j-1];j++) a_[index]+=a[j-1];
		n_-=j;index++;*/
	}
	/*if (length>=1000000000){
		cout<<c_[1]<<a_[1]<<" "<<c_[2]<<a_[2]<<" "<<c_[3]<<a_[3];
		unsigned long long m=0; char las; long long last=0;
		for (index=1;m*2<=length&&index*2<n_;index++){
			if (last&&las!=((last>0)?c_[n+1-index]:c_[index])) {
				if (last>0) a_[index]-=last;
				else a_[n+1-index]+=last;
			}
			if (c_[index]!=c_[n+1-index]) {
				result += min(a_[index],a_[n+1-index]); m+=min(a_[index],a_[n+1-index]);
				last = a[index]-a[n+1-index];
				las = ((a[index]>a[n+1-index])?c[index]:c[n+1-index]);
			}
		}
	} else */
		for (unsigned long long i=0;i*2<length;i++) result+=(input[i]!=input[length-i-1]);
	cout<<result<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
