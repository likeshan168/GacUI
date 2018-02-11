/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
GacUI Reflection: Shared Script

Interfaces:
***********************************************************************/

#ifndef VCZH_PRESENTATION_REFLECTION_GUIINSTANCEANIMATION
#define VCZH_PRESENTATION_REFLECTION_GUIINSTANCEANIMATION

#include "../Resources/GuiResource.h"
#include "../../Import/VlppWorkflowCompiler.h"

namespace vl
{
	namespace presentation
	{
		class GuiInstanceAnimation : public Object, public Description<GuiInstanceAnimation>
		{
		public:
		};

		class GuiInstanceGradientAnimation : public GuiInstanceAnimation, public Description<GuiInstanceGradientAnimation>
		{
		public:
			struct Target
			{
				WString									name;
				WString									interpolation;

				GuiResourceTextPos						namePosition;
				GuiResourceTextPos						interpolationPosition;
			};

			using EnumerateMemberAccessor = const Func<Ptr<workflow::WfExpression>(Ptr<workflow::WfExpression>)>&;
			using EnumerateMemberCallback = const Func<void(EnumerateMemberAccessor)>&;

			WString										className;
			WString										typeName;
			WString										interpolation;
			collections::List<Target>					targets;

			GuiResourceTextPos							tagPosition;
			GuiResourceTextPos							classPosition;
			GuiResourceTextPos							typePosition;
			GuiResourceTextPos							interpolationPosition;

			static Ptr<GuiInstanceGradientAnimation>	LoadFromXml(Ptr<GuiResourceItem> resource, Ptr<parsing::xml::XmlDocument> xml, GuiResourceError::List& errors);
			Ptr<parsing::xml::XmlElement>				SaveToXml();

			bool										IsSupportedPrimitiveType(description::ITypeDescriptor* td);
			vint										ValidateStructMembers(GuiResourceTextPos namePosition, description::ITypeDescriptor* td, const WString& prefix, GuiResourceError::List& errors);
			vint										ValidatePropertyType(GuiResourceTextPos namePosition, description::ITypeInfo* typeInfo, const WString& prefix, GuiResourceError::List& errors, bool rootValue = false);

			void										EnumerateMembers(EnumerateMemberCallback callback, EnumerateMemberAccessor accessor, description::IPropertyInfo* propInfo);
			void										EnumerateMembers(EnumerateMemberCallback callback, EnumerateMemberAccessor accessor, description::ITypeDescriptor* td);
			void										EnumerateProperties(EnumerateMemberCallback callback, description::ITypeDescriptor* td);
			Ptr<workflow::WfModule>						Compile(GuiResourcePrecompileContext& precompileContext, const WString& moduleName, bool generateImpl, GuiResourceError::List& errors);
		};
	}
}

#endif