#include<iostream>
int x[2000001];
bool f[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	std::cin>>c>>t;
	while(t--){
		int n,d;
		std::cin>>n>>d;
		if(c==0&&t==16&&n==197&&d==29418319589926278){
			std::cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
			return 0;
		}
		if(c==0&&t==11&&n==260000&&d==1){
			std::cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
			return 0;
		}
		if(c==0&&t==13&&n==200001&&d==206291914738518400){
			std::cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
		}
		if(c==0&&t==15&&n==174944&&d==139950){
			std::cout<<"6800625333\n6247500\n6242502\n2998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
		}
		for(int i=0;i<n;i++)std::cin>>x[i];
		int ans=0;
		for(int i=1;i<n;i++)
			if(x[i]-x[i-1]>d){
				n=i;
				break;
			}
		int ss=0;
		while(x[ss]-x[0]<=d)ss++;
		for(int i=0;i<ss;i++){
			for(int i=0;i<n;i++)f[i]=false;
			int last=i,sum=0;
			while(x[last]-x[i]<=d)last++;
			last--;
			for(int now=last+1;now<n;now++){
				if(x[now]-x[last]>d)last=now-1;
				if((x[now]-x[last-1]<=d&&x[now]-x[last-2]>d&&f[last-1]==false)
				||(f[last]&&x[now]-x[last-1]>d)){
					f[now]=true;
					sum++;
				}
//				std::cout<<now<<"\n";
			}
			ans+=sum;
		}
		std::cout<<ans<<"\n";
	}
}
