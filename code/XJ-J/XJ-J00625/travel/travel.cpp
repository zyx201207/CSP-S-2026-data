ind<std
usting <std>
int mian{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,da[5]={ },a,b;
	char q,p;
	cin>>c1>>a>>q;
	cin>>c1>>b>>q;
	if(c1==c2) {
		da[1]=1;
		if(a==b) {
			da[2]=1;
			if((q<='C'&&p<='C')||(p>'C'&&q>'C')) {
				da[3]=1;
				if(q<='C'&&p<='C') {
					da[4]=1;
				}
			}
		}
	}
	for(int i=1; i<=4; i++) {
		cout<<a[i];
	}
}