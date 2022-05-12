#ifndef MATRIXINDEX_H
#define MATRIXINDEX_H

//typedef struct{
//   long long z,x,c,v,b,n,m,a,s,d,f,g,h,k,l,q,w,e,r,t,y,u,o,p,asd,dsd,dsddsds,zx,xc,cv,vb,bn,nm,zc,xv,cb,vn,bm,
//      as,sd,df,fg,gh,hj,jk,kl,lk,kj,jh,hg,gf,fd,ds,sa,az,za,sx,xs,dc,cd,fv,vf,gb,bg,hn,nh,jm,mj,qa,aq,ws,sw,
//      ed,de,rf,fr,tg,gt,yh,hy,uj,ju,ki,ik,ol,lo,se,es,dr,rd,ft,tf,gy,yg,hu,uh,ji,ij,ko,ok,lp,pl;
//}asdasd;
//
//typedef struct{
//   asdasd z,x,c,v,b,n,m,a,s,d,f,g,h,k,l,q,w,e,r,t,y,u,o,p,asd,dsd,dsddsds,zx,xc,cv,vb,bn,nm,zc,xv,cb,vn,bm,
//      as,sd,df,fg,gh,hj,jk,kl,lk,kj,jh,hg,gf,fd,ds,sa,az,za,sx,xs,dc,cd,fv,vf,gb,bg,hn,nh,jm,mj,qa,aq,ws,sw,
//      ed,de,rf,fr,tg,gt,yh,hy,uj,ju,ki,ik,ol,lo,se,es,dr,rd,ft,tf,gy,yg,hu,uh,ji,ij,ko,ok,lp,pl;
//}zxczxc;

class MatrixIndex{
   public:
      unsigned char i,j;
      char killedPieceI, killedPieceJ;
//      zxczxc z,x,c,v,b,n,m,a,s,d,f,g,h,k,l,q,w,e,r,t,y,u,o,p,asd,dsd,dsddsds,zx,xc,cv,vb,bn,nm,zc,xv,cb,vn,bm,
//      as,sd,df,fg,gh,hj,jk,kl,lk,kj,jh,hg,gf,fd,ds,sa,az,za,sx,xs,dc,cd,fv,vf,gb,bg,hn,nh,jm,mj,qa,aq,ws,sw,
//      ed,de,rf,fr,tg,gt,yh,hy,uj,ju,ki,ik,ol,lo,se,es,dr,rd,ft,tf,gy,yg,hu,uh,ji,ij,ko,ok,lp,pl;

      MatrixIndex();
      MatrixIndex(unsigned char i, unsigned char j);
      MatrixIndex(unsigned char i, unsigned char j, char killedPieceI, char killedPieceJ);
      virtual ~MatrixIndex();

   protected:

   private:
};

#endif // MATRIXINDEX_H
