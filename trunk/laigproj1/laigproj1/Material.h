 class Material 
   {
   private:
		float* shininess; 
		float* specular;	/* specular reflection. */
		float* diffuse;	/* diffuse reflection. */
		float* ambient;	/* ambient reflection. */   
   public:
	    Material(float* shininess, float* specular,
						float* diffuse, float* ambient);
		 void activate();
   };
